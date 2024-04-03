#ifndef TEXT_H
#define TEXT_H

#include <string>

constexpr std::string_view ERROR_TEXT = "Oops, that input is invalid. Please try again.\n";

constexpr std::string_view INIT_TEXT = ".--------------------------------------------------.\n"
                                       "|                       MODE                       |\n"
                                       "|--------------------------------------------------|\n"
                                       "| (1)  User mode                                   |\n"
                                       "| (2)  Auto generated mode (for performance test)  |\n"
                                       "|                                                  |\n"
                                       "| (00) Exit                                        |\n"
                                       "*--------------------------------------------------*\n";

constexpr std::string_view START_TEXT = ".--------------------------------------------------.\n"
                                        "|                      START                       |\n"
                                        "|--------------------------------------------------|\n"
                                        "| (1)  Login                                       |\n"
                                        "| (2)  New user                                    |\n"
                                        "|                                                  |\n"
                                        "| (0)  Mode                                        |\n"
                                        "| (00) Exit                                        |\n"
                                        "*--------------------------------------------------*\n";

constexpr std::string_view LOGIN_TEXT = ".--------------------------------------------------.\n"
                                        "|                      LOGIN                       |\n"
                                        "|--------------------------------------------------|\n";

constexpr std::string_view NEW_USER_TEXT = ".--------------------------------------------------.\n"
                                           "|                     NEW USER                     |\n"
                                           "|--------------------------------------------------|\n"
                                           "| Enter your user name!                            |\n"
                                           "|                                                  |\n"
                                           "| (00) Cancel                                      |\n"
                                           "*--------------------------------------------------*\n";

constexpr std::string_view USER_HOME_TEXT = ".--------------------------------------------------.\n"
                                            "|                    USER HOME                     |\n"
                                            "|--------------------------------------------------|\n"
                                            "| (1) Join group                                   |\n"
                                            "| (2) New group                                    |\n"
                                            "| (3) My groups                                    |\n"
                                            "|                                                  |\n"
                                            "| (0) Log-out                                      |\n"
                                            "*--------------------------------------------------*\n";

constexpr std::string_view NEW_GROUP_TEXT = ".--------------------------------------------------.\n"
                                            "|                    NEW GROUP                     |\n"
                                            "|--------------------------------------------------|\n"
                                            "| Enter group name!                                |\n"
                                            "|                                                  |\n"
                                            "| (00) Cancel                                      |\n"
                                            "*--------------------------------------------------*\n";
constexpr std::string_view CHOOSE_GROUP_TEXT = ".--------------------------------------------------.\n"
                                               "|                   CHOOSE GROUP                   |\n"
                                               "|--------------------------------------------------|\n";

constexpr std::string_view JOIN_GROUP_TEXT = ".--------------------------------------------------.\n"
                                             "|                    JOIN GROUP                    |\n"
                                             "|--------------------------------------------------|\n";

constexpr std::string_view GROUP_HOME_TEXT = ".--------------------------------------------------.\n"
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

// std::string_view GROUP_MEMBER_TEXT =

constexpr std::string_view ADD_EXPENSE_TEXT = ".--------------------------------------------------.\n"
                                              "|                    ADD EXPENSE                   |\n"
                                              "|--------------------------------------------------|\n"
                                              "| Add expense in Euro!                             |\n"
                                              "|                                                  |\n"
                                              "| (00) Cancel                                      |\n"
                                              "*--------------------------------------------------*\n";

constexpr std::string_view CHECK_EXPENSE_TEXT = ".--------------------------------------------------.\n"
                                                "|                     EXPENSES                     |\n"
                                                "|--------------------------------------------------|\n";

constexpr std::string_view SETTLEMENT_TEXT = ".--------------------------------------------------.\n"
                                             "|                   SETTLEMENTS                    |\n"
                                             "|--------------------------------------------------|\n";

constexpr std::string_view LEAVE_GROUP_TEXT = ".--------------------------------------------------.\n"
                                              "|                 LEAVING GROUP...                 |\n"
                                              "*--------------------------------------------------*\n";

constexpr std::string_view EDIT_EXPENSE_TEXT = ".--------------------------------------------------.\n"
                                               "|                   EDIT EXPENSE                   |\n"
                                               "|--------------------------------------------------|\n"
                                               "| Give in the amount you want to change Euro!      |\n"
                                               "|                                                  |\n"
                                               "| (00) Cancel                                      |\n"
                                               "*--------------------------------------------------*\n";

constexpr std::string_view EXIT_TEXT = ".--------------------------------------------------.\n"
                                       "|                    EXITING...                    |\n"
                                       "|--------------------------------------------------|\n"
                                       "| See you next time!                               |\n"
                                       "*--------------------------------------------------*\n";

#endif