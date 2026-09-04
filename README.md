*This project has been created as part of the 42 curriculum by naratass*

## Description
The **Philosophers** project is part of the core curriculum at 42 School. Its primary goal is to introduce the basics of threading a process and synchronization mechanisms. Through this project, you will learn how to create threads and use mutexes to solve the classic **Dining Philosophers problem** formulated by Edsger W. Dijkstra.

**Brief Overview:**
In this simulation, one or more philosophers sit at a round table with a large bowl of spaghetti in the middle. The philosophers alternate between three states: **eating**, **sleeping**, and **thinking**. 
- There are as many forks on the table as there are philosophers.
- A philosopher needs two forks (left and right) to eat.
- Once a philosopher finishes eating, they put down their forks and go to sleep. Upon waking, they start thinking again.
- The simulation stops when a philosopher dies of starvation. The challenge is to orchestrate the threads (philosophers) and shared resources (forks) efficiently to prevent deadlocks, data races, and starvation.

---

## Instructions

### Compilation & Installation
This project is written in C and uses a `Makefile` for compilation. No external libraries are required other than the standard POSIX threads library.

To compile the project, clone the repository and run the following command in the root directory:
```bash
make
```
This will compile the source files and generate an executable named `philo`.

Other available `make` rules:
- `make clean`: Removes the compiled object files (`.o`).
- `make fclean`: Removes the object files and the `philo` executable.
- `make re`: Recompiles the entire project (executes `fclean` followed by `make`).

### Execution
Run the program with the following arguments:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**Arguments breakdown:**
- `number_of_philosophers`: The number of philosophers (and forks) at the table.
- `time_to_die` (in ms): If a philosopher doesn’t start eating `time_to_die` milliseconds after the beginning of their last meal or the start of the simulation, they die.
- `time_to_eat` (in ms): The time it takes for a philosopher to eat (while holding two forks).
- `time_to_sleep` (in ms): The time a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat` *(optional)*: If all philosophers eat at least this many times, the simulation stops. If not specified, the simulation runs until a philosopher dies.

---

## Features & Technical Choices

- **Language**: C
- **Concurrency**: Parallel execution is achieved using POSIX threads (`pthread_create`, `pthread_join`). Every philosopher is a thread.
- **Synchronization**: Prevention of data races and deadlocks using Mutexes (`pthread_mutex_t`). Each fork is protected by a mutex to ensure only one philosopher can interact with it at a time. Printing to the standard output is also protected by a mutex to avoid scrambled text.
- **Performance Constraints**: No global variables are allowed, and the program must have zero memory leaks and zero data races. 

---

## Usage Examples

**Example 1: A stable simulation**
```bash
./philo 5 800 200 200
```
*5 philosophers sit at the table. They have plenty of time to eat, sleep, and think. No one should die.*

**Example 2: Simulation with an eating limit**
```bash
./philo 5 800 200 200 7
```
*The simulation will safely halt after every philosopher has eaten at least 7 times.*

**Example 3: A philosopher dies**
```bash
./philo 4 310 200 100
```
*A philosopher will eventually starve and die because the timing constraints are too tight to share the forks effectively among 4 philosophers.*

---

## Resources

### Classic References
- **[Dining Philosophers Problem - Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)**: The original theoretical problem and its edge cases.
- **[POSIX Threads (pthreads) Tutorial](https://hpc-tutorials.llnl.gov/posix/)**: A comprehensive guide on creating and managing multithreading in C.
- **[Mutexes in C](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/)**: Explanation of mutex locks for thread synchronization.
- **[Valgrind & ThreadSanitizer](https://clang.llvm.org/docs/ThreadSanitizer.html)**: Essential tools used for debugging data races and memory leaks in multithreaded applications.

### AI Usage
During the development of this project, Artificial Intelligence was utilized to assist with the following tasks:
- **Code Refactoring & Logic Check**: AI models (such as ChatGPT/GitHub Copilot) were used to review the thread creation loops, refine the locking mechanisms (mutexes) to avoid deadlock scenarios, and optimize the millisecond timestamp calculations.
- **Debugging Data Races**: Output logs from ThreadSanitizer were fed into the AI to help pinpoint exactly which variables were unprotected and causing data races, providing strategies for securing read/write operations with mutexes.
- **Documentation**: AI was used to help structure, format, and generate the contents of this `README.md` to ensure clarity and standard formatting.
