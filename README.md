# ATM GUI Project

This project implements C++/CLI and net programming for a simulation of an ATM. The purpose of this project was to create a simulated experience of using an ATM with a pad with buttons to press that would effect the ATM window and practice net programming. It also uses TCP so that it can pass information to a server, which in this case, is the ATM. The client side would be the pad with interactable buttons to press. Along with TCP usage, this program also uses threads in order to give some parts of the program time to process a function or wait for an acknowledgement of something. They were also used so that both windows could be opened at the same time.

When run, this project will open 2 windows forms. As mentioned previously, the pad with contain buttons the user can press to interact with the ATM by entering an account.
PLEASE NOTE: When entering an account, only these combinations of account numbers and pins will work. Entering a wrong combination will unfortunately lead to a crash. 

		Account 1: 101 AND 101
		Account 2: 102 AND 201
		Account 3: 103 AND 301
		Account 4: 104 AND 401
		Account 5: 105 AND 501

You'll notice that along with the numbers (also the CE and . options) buttons, there are 3 buttons at the bottom that will change depending on which stage of the ATM simulation you're on. These buttons are vital for communication between the client (Number Pad) and the server (ATM). 
Leaving each account won't erase their data so if you decide to switch to a different account and withdraw/deposit numbers there, it won't change a thing to a previously used account.
