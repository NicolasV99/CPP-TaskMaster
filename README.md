# Overview

The purpose of writing this software was to deepen my understanding of C++ memory management and file persistence. As a software engineer, I wanted to move beyond basic syntax and build a functional console application that uses **Data Structures** (vectors and structs) to manage information in memory and **File Stream libraries** to store that data permanently on the disk.

This software is a Console-based To-Do List Manager. It allows users to:
* Add new tasks to a dynamic list.
* View all current tasks with their status.
* Delete completed tasks.
* Automatic Persistence: The app automatically loads data from a text file upon startup and saves changes when the user exits.

{Provide a link to your YouTube demonstration. It should be a 4-5 minute demo of the software running and a walkthrough of the code. Focus should be on sharing what you learned about the language syntax.}

[Software Demo Video](http://youtube.link.goes.here)

# Development Environment

To develop this software, I used the following tools and technologies:

* IDE: Visual Studio Community 2022 (configured with the "Desktop development with C++" workload).
* Language: C++ (Standard 11 or higher).
* Key Libraries:
    * `<iostream>`: For console input/output handling.
    * `<vector>`: For dynamic array management (storing the list of tasks).
    * `<fstream>`: For file handling (reading and writing the `tasks.txt` database).
    * `<string>`: For string manipulation.

# Useful Websites

I found the following websites helpful during the development of this project:

* [CPlusPlus.com - Vector Documentation](https://cplusplus.com/reference/vector/vector/) 
* [W3Schools C++ Files](https://www.w3schools.com/cpp/cpp_files.asp) - 
* [Visual Studio C++ Setup](https://learn.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-170) 

# Future Work

The following is a list of things that I plan to improve and add to the project in the future:

* Mark as Completed: Add a specific function to toggle a task's status (True/False) without deleting it.
* Task Categories: Update the `struct` to include a category string (e.g., "Work", "Personal") and allow filtering by category.
* Input Validation: Improve the `cin` error handling to prevent the program from crashing if the user enters a letter instead of a number in the menu.
* Better ID Management: Currently, IDs are based on the vector size. I would like to implement a robust unique ID system so IDs don't shift when a task is deleted.