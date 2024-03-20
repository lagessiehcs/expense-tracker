# Expense Tracker

Hey, thank you for using my program!

## Compilation

### Compilation with Cmake
The code can be compiled alternatively using Cmake:
```
mkdir build
cd ./build 
cmake -S ../src/ -G "Unix Makefiles"
make
```

## Profiling
For profiling (GNU profiler) use in the terminal on Linux
```
g++ -pg main.cpp backend.cpp Expense.cpp frontend.cpp Group.cpp printers.cpp User.cpp auto_generate.cpp -o main
```
in the folder `Our_ExpenseTracker`.


## Using the Program 
The first thing you need to do when running the app, is choosing a mode:   
(1): User mode: Choose this mode if you want to use the app as a normal user.   
(2): Auto generated mode: Choose this mode if you want to perform performance tests.   

Additional Info for user mode: The program is built with different pages (or levels). Sadly, we were not able to only show the refreshed screen, meaning the refreshed screen is successively printed in the terminal. To navigate, you just need to enter the respective numbers and hit enter!

## Program Functionality and File Structure

The program is a while loop that waits for inputs. As already mentioned, the program has multiple different pages (or levels); we refer to this as the ``screen_id``. As soon as an input is registered, the program checks what the current ``screen_id`` is to know what to do with the input (calling a function) and changes the ``screen_id`` afterwards. Finally, the respective page to the ``screen_id`` is printed in the terminal, and the process starts all over again.   

The program consists of the following files:

- ``main.cpp``: Initiates the main (terminal) loop and calls the two functions ``update_terminal`` and ``get_and_compute_input``, which are defined in ``frontend.cpp``. OR: initiates auto generate mode by calling ``import_data`` and ``auto_run``, which are defined in ``auto_generate.cpp``.

- ``frontend.cpp``: Contains the two functions ``update_terminal`` and ``get_and_compute_input``. These two functions form the frontend. The first function inhabits the visuals of all pages and prints the respective page in the terminal. The latter function is responsible for the input handling, which means it decides what to do with the input and what screen to show next.   

- ``printers.cpp``: This file is basically an extension to the frontend. It contains additional functions that print information to the terminal. For example, the function ``print_all_users``, which prints, ...big surprise, all user names, is defined here.

- ``backend.cpp``: The backend contains functions that interact between different objects.

- ``Expense.cpp``, ``Group.cpp``, ``User.cpp``: In these files the respective objects are defined.

- ``auto_generate.cpp``: Contains the functions ``import_data`` and ``auto_run``. Which load and run a .csv file for performance tests.

Have fun settling expenses with your friends!
