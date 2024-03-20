#ifndef TEXT_H
#define TEXT_H

#include <string>

inline std::string ERROR_TEXT = "\nOops, that input is invalid.  Please try again.\n";

inline std::string INIT_TEXT = "\n=================================================\n"
                               "Choose mode:\n"
                               "(1): User mode\n"
                               "(2): Auto generated mode (for performance test)\n"
                               "=================================================\n";

inline std::string START_TEXT = "\n=================================================\n"
                                "(1) Login\n"
                                "(2) Create new user\n"
                                "(0) Exit\n"
                                "=================================================\n";

// inline std::string CHOOSE_USER_TEXT = "\n=================================================\n"
//                                "=================================================\n";

inline std::string CREATE_USER_TEXT = "\n=================================================\n"
                                      "Enter your user name!\n"
                                      "=================================================\n";

inline std::string USER_HOME_TEXT = "\n=================================================\n"
                                    "(1) Join group\n"
                                    "(2) Create group\n"
                                    "(3) My groups\n"
                                    "(0) Log-out\n"
                                    "=================================================\n";

inline std::string CREATE_GROUP_TEXT = "\n=================================================\n"
                                       "Enter group name!\n"
                                       "=================================================\n";

inline std::string GROUP_HOME_TEXT = "\n=================================================\n"
                                     "(1) Add expense\n"
                                     "(2) Check expenses\n"
                                     "(3) My balance\n"
                                     "(4) Create Settlement\n"
                                     "(5) Group members\n"
                                     "(6) Leave group\n"
                                     "(0) Back\n"
                                     "=================================================\n";

// inline std::string GROUP_MEMBER_TEXT =

inline std::string ADD_EXPENSE_TEXT = "\n=================================================\n"
                                      "Add expense!\n"
                                      "=================================================\n";

// inline std::string CHECK_EXPENSE_TEXT = "\n=================================================\n"
//                                  "Check expense!\n"
//                                  "=================================================\n";

// inline std::string SETTLEMENT_TEXT = "\n=================================================\n"
//                                  "Settlement!\n"
//                                  "=================================================\n";

inline std::string LEAVE_GROUP_TEXT = "\n=================================================\n"
                                      "This feature is not yet available."
                                      "(0) Back\n"
                                      "=================================================\n";

inline std::string EDIT_EXPENSE_TEXT = "\n=================================================\n"
                                       "Edit expense!\n"
                                       "=================================================\n";

inline std::string EXIT_TEXT = "\n=================================================\n"
                               "See you next time!\n"
                               "=================================================\n";

#endif