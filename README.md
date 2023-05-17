# Graduate Admission System

This repository contains the code for a graduate admission system implemented in C++ for both Domestic and International students. The admission system utilizes singly linked lists, and a variety of searching, insertion, and deletion functions, as well as unit tests and complexity analysis of sorting algorithms. The project is organized into four main parts:

## Part 1: Singly Linked List based System

The project uses two singly linked lists to store DomesticStudent and InternationalStudent objects, initialized from input files. The linked lists are always sorted based on the overall sorting scheme implemented. The system provides the following functionalities:

- Inserting new student objects
- Searching student objects based on different criteria (application id, cgpa, researchScore, firstName, and lastName)
- Deleting student objects based on firstName and lastName
- Merging the DomesticStudent and InternationalStudent linked lists into a single sorted Student linked list

## Part 2: Robust Error Checking

Error checking is implemented to handle a variety of cases, including:

- Missing input fields in the input files
- Case-insensitive string matching
- Checking for valid input field values
- Handling invalid user input selection options
- Using try-throw-catch for error checking when allocating new memory space

## Part 3: Unit Testing

Unit tests are implemented to validate the following major functions:

- Insertion of DomesticStudent and InternationalStudent objects
- Searching for objects in linked lists based on different criteria
- Deletion of objects in linked lists based on firstName and lastName
- Merging the sorted linked lists into a single Student linked list
- Searching objects in the merged linked list based on cgpa_threshold and researchScore_threshold

## Part 4: Algorithm Complexity Analysis

The complexity of the insert, search, deletion, and merge functions was analyzed using the big-O notation. Three sorting algorithms were tested - heap sort, merge sort, and quick sort. Merge sort was found to be the best choice for this project.

# Getting Started

1. Clone this repository.

<pre><div class="bg-black rounded-md mb-4"><div class="flex items-center relative text-gray-200 bg-gray-800 px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span></span><button class="flex ml-auto gap-2"><svg stroke="currentColor" fill="none" stroke-width="2" viewBox="0 0 24 24" stroke-linecap="round" stroke-linejoin="round" class="h-4 w-4" height="1em" width="1em" xmlns="http://www.w3.org/2000/svg"><path d="M16 4h2a2 2 0 0 1 2 2v14a2 2 0 0 1-2 2H6a2 2 0 0 1-2-2V6a2 2 0 0 1 2-2h2"></path><rect x="8" y="2" width="8" height="4" rx="1" ry="1"></rect></svg></button></div><div class="p-4 overflow-y-auto"><code class="!whitespace-pre hljs language-bash">git clone https://github.com/yourusername/GraduateAdmissionSystem.git
</code></div></div></pre>

2. Use the provided Makefile to compile the C++ files.

<pre><div class="bg-black rounded-md mb-4"><div class="flex items-center relative text-gray-200 bg-gray-800 px-4 py-2 text-xs font-sans justify-between rounded-t-md"><span></span><button class="flex ml-auto gap-2"><svg stroke="currentColor" fill="none" stroke-width="2" viewBox="0 0 24 24" stroke-linecap="round" stroke-linejoin="round" class="h-4 w-4" height="1em" width="1em" xmlns="http://www.w3.org/2000/svg"><path d="M16 4h2a2 2 0 0 1 2 2v14a2 2 0 0 1-2 2H6a2 2 0 0 1-2-2V6a2 2 0 0 1 2-2h2"></path><rect x="8" y="2" width="8" height="4" rx="1" ry="1"></rect></svg></button></div><div class="p-4 overflow-y-auto"><code class="!whitespace-pre hljs language-go">make
</code></div></div></pre>

3. Run the compiled executable.

<pre><div class="bg-black rounded-md mb-4"><div class="flex items-center relative text-gray-200 bg-gray-800 px-4 py-2 text-xs font-sans justify-between rounded-t-md"><button class="flex ml-auto gap-2"><svg stroke="currentColor" fill="none" stroke-width="2" viewBox="0 0 24 24" stroke-linecap="round" stroke-linejoin="round" class="h-4 w-4" height="1em" width="1em" xmlns="http://www.w3.org/2000/svg"><path d="M16 4h2a2 2 0 0 1 2 2v14a2 2 0 0 1-2 2H6a2 2 0 0 1-2-2V6a2 2 0 0 1 2-2h2"></path><rect x="8" y="2" width="8" height="4" rx="1" ry="1"></rect></svg></button></div><div class="p-4 overflow-y-auto"><code class="!whitespace-pre hljs">./AdmissionSystem
</code></div></div></pre>

4. Follow the prompts to interact with the graduate admission system.

# Contributing

We welcome contributions to improve the graduate admission system. To contribute:

1. Fork this repository.
2. Create a new branch with a descriptive name for your feature or bugfix.
3. Make your changes, ensuring that you follow the existing code style and practices.
4. Commit your changes with a clear and concise commit message.
5. Create a pull request to the original repository, describing your changes and how they improve the project.

Before submitting a pull request, please make sure your code compiles and passes all the provided unit tests.
