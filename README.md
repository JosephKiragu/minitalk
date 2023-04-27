# Minitalk

Minitalk is a simple communication program that uses UNIX signals to send and receive messages between two processes (a client and a server). This project demonstrates the basics of inter-process communication using UNIX signals.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)

## Prerequisites

- UNIX-based OS (Linux or macOS)
- GCC compiler

## Installation

1. Clone the repository:

   ```
   git clone https://github.com/JosephKiragu/minitalk.git
   ```

2. Change to the project directory:

   ```
   cd minitalk
   ```

3. Compile the server and client:

   ```
   make
   ```

## Usage

1. Run the server:

   ```
   ./server
   ```

   The server will display its process ID (PID) on the console.

2. Open a new terminal window and run the client, passing the server's PID and the message you want to send as arguments:

   ```
   ./client [server_pid] [message]
   ```

   For example:

   ```
   ./client 12345 "Hello, Minitalk!"
   ```

3. The server will display the received message on the console. The client will display "sending successful" upon successful transmission.

## Project Structure

- `server.c`: Contains the server program that receives messages from the client process and prints them on the console.
- `client.c`: Contains the client program that sends messages to the server process using UNIX signals.
- `minitalk.h`: Header file containing necessary function prototypes and includes.
- `utility.c`: Contains utility functions for string manipulation, character output, and number conversion.

For more information on how the program works, see the detailed comments in the source code.
