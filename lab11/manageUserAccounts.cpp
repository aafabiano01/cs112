/* manageUserAccounts.cpp contains the "driver" for class AccountManager.
 * Joel Adams, for CS 112 at Calvin University.
 */

#include "AccountManager.h"

int main() {
	AccountManager manager("accountInfo.txt");
	manager.run();
}
