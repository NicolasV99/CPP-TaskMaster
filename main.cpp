#include <iostream>
#include <vector>
#include <string>
#include <fstream> // Library for file handling (New!)

using namespace std;

// 1. DEFINE TASK STRUCTURE
struct Task {
    int id;
    string description;
    bool completed;
};

// 2. FUNCTION DECLARATIONS
void showMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);
void saveToFile(const vector<Task>& tasks);
void loadFromFile(vector<Task>& tasks);    

int main() {
    vector<Task> tasks;
    int option = 0;

    // LOAD DATA AUTOMATICALLY AT START
    loadFromFile(tasks);

    cout << "--- WELCOME TO CPP-TASKMASTER ---" << endl;

    // 3. MAIN LOOP
    do {
        showMenu();
        cout << "Choose an option: ";
        if (!(cin >> option)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore(); 

        switch (option) {
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            deleteTask(tasks);
            break;
        case 4:
            // SAVE DATA AUTOMATICALLY ON EXIT
            saveToFile(tasks);
            cout << "Exiting program... Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }

        cout << endl;

    } while (option != 4);

    return 0;
}

// --- FUNCTION IMPLEMENTATIONS ---

void showMenu() {
    cout << "----------------------" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Save & Exit" << endl;
    cout << "----------------------" << endl;
}

void addTask(vector<Task>& tasks) {
    string desc;
    cout << "Enter task description: ";
    getline(cin, desc);

    if (desc.empty()) {
        cout << "Task description cannot be empty." << endl;
        return;
    }

    Task newTask;
    newTask.id = tasks.size() + 1;
    newTask.description = desc;
    newTask.completed = false;

    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    cout << "--- TASK LIST ---" << endl;
    if (tasks.empty()) {
        cout << "No pending tasks." << endl;
    }
    else {
        for (size_t i = 0; i < tasks.size(); i++) {
            string status = tasks[i].completed ? "[X]" : "[ ]";
            cout << i + 1 << ". " << status << " " << tasks[i].description << endl;
        }
    }
}

void deleteTask(vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;

    int index;
    cout << "Enter the task NUMBER to delete: ";
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + (index - 1));
        cout << "Task deleted successfully." << endl;
    }
    else {
        cout << "Invalid task number." << endl;
    }
}

// --- FILE HANDLING FUNCTIONS (PERSISTENCE) ---

void saveToFile(const vector<Task>& tasks) {
    ofstream outFile("tasks.txt"); 
    if (outFile.is_open()) {
        for (const auto& task : tasks) {
            outFile << task.id << "|" << task.description << "|" << task.completed << endl;
        }
        outFile.close();
        cout << "Data saved to tasks.txt successfully." << endl;
    }
    else {
        cout << "Error: Could not save data!" << endl;
    }
}

void loadFromFile(vector<Task>& tasks) {
    ifstream inFile("tasks.txt"); 
    if (inFile.is_open()) {
        tasks.clear();
        string line;

        while (getline(inFile, line)) {
            Task newTask;
            size_t pos1 = line.find('|');
            size_t pos2 = line.rfind('|');

            if (pos1 != string::npos && pos2 != string::npos) {
                newTask.id = stoi(line.substr(0, pos1));
                newTask.description = line.substr(pos1 + 1, pos2 - pos1 - 1);
                newTask.completed = stoi(line.substr(pos2 + 1));

                tasks.push_back(newTask);
            }
        }
        inFile.close();
        // cout << "Data loaded successfully." << endl;
    }
}