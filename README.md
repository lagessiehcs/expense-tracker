# Expense Tracker

Idea contributed by Gia-Phong Tran giaphong.tran@tum.de and Peter Riske peter.riske@tum.de.

## Motivation

The goal of this project is to build a tool which helps people to have an overview over their group expenses. This tool is supposed to track common expenses (spent in a group or as a single individual) and to create an overview over the cash flows, e.g. of a group vacation. The Expense Tracker makes it easy to split bills with friends and family - everybody can see who they owe. Whether you are sharing a beach vacation, splitting rent with roommates or paying someone back for dinner, it makes life just easier!

The Expense Tracker is able to share group expenses in an efficient way, i.e. to reduce the number of necessary transactions. Users of this tool will be able to view the status of their own account and the balance of their groups.

## Building

In your terminal:

```shell
mkdir build
cd build 
cmake -S ../src/ -G "Unix Makefiles"
make
```
## Running

In your terminal:

```shell
./ExpenseTracker
```

## Using the Program 
The first thing you need to do when running the app, is choosing a mode:   
(1): User mode: Choose this mode if you want to use the app as a normal user.   
(2): Auto generated mode: Choose this mode if you want to perform performance tests.   

Additional Info for user mode: The program is built with different pages (or levels). To navigate, you just need to enter the respective numbers and hit enter!

Have fun settling expenses with your friends!
