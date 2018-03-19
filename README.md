# Map ADT Comp 220 2018
Comp220 @ Capilano U - Map ADT class collaboration project (2018)

## Project Requirements
This project has 4 "deliverable" C modules:
 - __HashMap ADT__ – a [hash table](https://en.wikipedia.org/wiki/Hash_table) implementation of the Map API
 - __TreeMap ADT__ – a [search tree](https://en.wikipedia.org/wiki/Search_tree) implementation of the Map API
 - __Map Unit Test Suite__ – a semi-automated suite of unit tests for the Map API
 - __Map Application__ – a small application program that uses the Map.

### Map API Specification
A Map ADT provides the following operations:
 - **`Insert(key, value)`**
   - **POST: Get(key) == value**
   - sets the value for key if `HasKey(key)`, otherwise inserts a new value in Map
 - **`Delete(key)`**
   - **POST: HasKey(key) == false**
   - removes the (key, value) pair from the Map, no effect if !HasKey(key)
 - **`Get(key)`**
   - **PRE: HasKey(key)**
   - returns the value associated with the given key
 - **`HasKey(key)`**
   - returns true iff the Map contains the given key
 - **`Size()`**
   - returns the number of (key, value) pairs in the Map
 - **`Clear()`**
   - **POST: Size() == 0**
   - removes all items from the Map (without creating memory leaks!)
 - **`KeySet()`**
   - returns a dynamic array containing all the Map Keys (in any sequence)
   - it is the caller's responsibility to free the returned array.

The public API should also include a "__constructor__" and a "__destructor__" function, used
by the client to create a new Map and free the Map when done.

The `HashMap` and `TreeMap` ADTs must provide _exactly_ the same public API.

### Word-Cloud Application Requirements

A ["Word Cloud"](https://en.wikipedia.org/wiki/Tag_cloud)
provides a visual representation of the frequency with which each word occurs in
a piece of text.  The first step in creating a Word Cloud is to perform a 
frequency analysis - parse the text and count the number of times each word occurs.

Our small, command-line application will perform this frequency analysis on
text read from file.  The name of the file is provided as a command line argument:

**`> wordcloud myTextFile.txt`**

The input file may be any plain text file with a maximum word size of 127 characters.  
"Words" are any token speparated by whitespace.
`fscanf(infile, " %127s", &word)` can be used to read one word, at most 127 characters, 
into a buffer (sized at least `char word[128]`).
However, parsing words while ignoring punctuation could be a significant challenge, 
so this functionality should be built in phases.

The program counts the frequency of each word in the input file and prints the 
frequency table to the console (stdout).  Something like:

| Word        | Frequency   |
| ----------- | ----------- |
| a           | 23 |
| the         | 13 |
| and         | 9 |
| you         | 5 |
| ...         | ... |

Notice that the frequency table is printed in descending order, by frequency.
The Sort Tree we built in the Lab would be a perfect way to sort the frequency count data.
