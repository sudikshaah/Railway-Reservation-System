# Railway-Reservation-System

This is a simple Railway Reservation System made using Python and SQL. 

It allows users to:
1. check train details
2.  book a ticket
3.  cancel a ticket
4.  check pnr status

#Requirements:-
1. python 3.X
2. MySQL/XAMPP
3. mysql-python-connector library

#setup instructions:-
1. Import 'rail(1).sql' file into your mysql database (using phpMyAdmin)
2. connect mysql and python by importing mysql.connector

Gemini said
Since you already have a Python version and a C version, your README should clearly highlight the upgrade in the C version (the Admin vs. User logic).

Here is a professional, copy-paste-ready Markdown template. You can paste this at the bottom of your existing README or use it to create a new README.md inside your C_Version folder.

🚂 Railway Reservation System (C Version)
This version of the project is a low-level implementation of a Railway Management System. Unlike the previous Python version, this iteration introduces Role-Based Access Control (RBAC) with separate modules for Administrators and Users.

🌟 New Features (C vs. Python)
Admin Section: Authorized access via Login ID and Password to manage the database.

User Section: Comprehensive menu-driven interface for passengers.

Data Persistence: Uses binary file handling (.dat files) to store data permanently.

Memory Efficiency: Built using C structs for optimized data mapping.

🛠️ Functionality Breakdown
Admin Module
Secure Login: Protected by a specific Admin ID and Password.

Add Trains: Input new train details (Number, Name, Route, Seats).

View All Trains: Display the complete list of trains currently in the database.

View All Bookings: Audit trail of all tickets booked by users.

User Module
Check Train Details: Real-time lookup of available trains.

Book a Ticket: Reserve a seat and generate a PNR status.

Cancel a Ticket: Remove a booking and update the database.

Check PNR Status: Verify the current status of a reservation.

📂 File Structure
C_Version/
├── project.c           # Main entry point & Login Logic
├── train.dat        # Binary database for train records
├── bookings.dat     # Binary database for user reservations
└── README.md        # Documentation
🚀 How to Run
Ensure you have a C compiler (like GCC) installed.

Open your terminal in the C_Version folder.

Compile the code:

Bash
gcc main.c -o railway_system
Run the executable:

Bash
./railway_system
Note: The default Admin credentials are hardcoded for initial setup. Ensure you change them in the source code before deployment.

Why the C Version is "Better"
While Python is great for quick prototyping, this C version helped me understand File Pointers, Structs, and Buffer Management. It handles data directly at a binary level, making it faster and more representative of how real embedded systems or legacy banking systems operate.
