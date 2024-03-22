#ifndef TEXT_H
#define TEXT_H

#include <string>

inline const std::string ERROR_TEXT = "Oops, that input is invalid.  Please try again.\n";

inline const std::string INIT_TEXT = ".--------------------------------------------------.\n"
                                     "|                       MODE                       |\n"
                                     "|--------------------------------------------------|\n"
                                     "| (1)  User mode                                   |\n"
                                     "| (2)  Auto generated mode (for performance test)  |\n"
                                     "|                                                  |\n"
                                     "| (00) Exit                                        |\n"
                                     "*--------------------------------------------------*\n";

inline const std::string START_TEXT = ".--------------------------------------------------.\n"
                                      "|                      START                       |\n"
                                      "|--------------------------------------------------|\n"
                                      "| (1)  Login                                       |\n"
                                      "| (2)  New user                                    |\n"
                                      "|                                                  |\n"
                                      "| (0)  Mode                                        |\n"
                                      "| (00) Exit                                        |\n"
                                      "*--------------------------------------------------*\n";

// inline std::string CHOOSE_USER_TEXT = "-------------------------------------------------\n"
//                                "-------------------------------------------------\n";

inline const std::string NEW_USER_TEXT = ".--------------------------------------------------.\n"
                                         "|                     NEW USER                     |\n"
                                         "|--------------------------------------------------|\n"
                                         "| Enter your user name!                            |\n"
                                         "*--------------------------------------------------*\n";

inline const std::string USER_HOME_TEXT = ".--------------------------------------------------.\n"
                                          "|                    USER HOME                     |\n"
                                          "|--------------------------------------------------|\n"
                                          "| (1) Join group                                   |\n"
                                          "| (2) New group                                    |\n"
                                          "| (3) My groups                                    |\n"
                                          "|                                                  |\n"
                                          "| (0) Log-out                                      |\n"
                                          "*--------------------------------------------------*\n";

inline const std::string NEW_GROUP_TEXT = ".--------------------------------------------------.\n"
                                          "|                    NEW_GROUP                     |\n"
                                          "|--------------------------------------------------|\n"
                                          "| Enter group name!                                |\n"
                                          "*--------------------------------------------------*\n";

inline const std::string GROUP_HOME_TEXT = ".--------------------------------------------------.\n"
                                           "|                    GROUP HOME                    |\n"
                                           "|--------------------------------------------------|\n"
                                           "| (1) Add expense                                  |\n"
                                           "| (2) Check expenses                               |\n"
                                           "| (3) My balance                                   |\n"
                                           "| (4) Create Settlement                            |\n"
                                           "| (5) Group members                                |\n"
                                           "| (6) Leave group                                  |\n"
                                           "|                                                  |\n"
                                           "| (0) Back                                         |\n"
                                           "*--------------------------------------------------*\n";

// inline std::string GROUP_MEMBER_TEXT =

inline const std::string ADD_EXPENSE_TEXT = ".--------------------------------------------------.\n"
                                            "|                    GROUP HOME                    |\n"
                                            "|--------------------------------------------------|\n"
                                            "| Add expense in Euro!                             |\n"
                                            "|                                                  |\n"
                                            "| (0) Cancel                                       |\n"
                                            "---------------------------------------------------*\n";

// inline std::string CHECK_EXPENSE_TEXT = "-------------------------------------------------\n"
//                                  "Check expense!\n"
//                                  "-------------------------------------------------\n";

// inline std::string SETTLEMENT_TEXT = "-------------------------------------------------\n"
//                                  "Settlement!\n"
//                                  "-------------------------------------------------\n";

inline const std::string LEAVE_GROUP_TEXT = ".--------------------------------------------------.\n"
                                            "|                   LEAVE_GROUP                    |\n"
                                            "|--------------------------------------------------|\n"
                                            "| This feature is not yet available.               |\n"
                                            "|                                                  |\n"
                                            "| (0) Back                                         |\n"
                                            "*--------------------------------------------------*\n";

inline const std::string EDIT_EXPENSE_TEXT = ".--------------------------------------------------.\n"
                                             "|                   EDIT EXPENSE                   |\n"
                                             "|--------------------------------------------------|\n"
                                             "| Give in the amount you want to change Euro!      |\n"
                                             "|                                                  |\n"
                                             "| (00) Cancel                                      |\n"
                                             "*--------------------------------------------------*\n";

inline const std::string EXIT_TEXT = ".--------------------------------------------------.\n"
                                     "|                    EXITING...                    |\n"
                                     "|--------------------------------------------------|\n"
                                     "| See you next time!                               |\n"
                                     "*--------------------------------------------------*\n";

#endif