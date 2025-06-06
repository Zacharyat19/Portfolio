/*
 * This program should compute the average and maximum age of all of the
 * people in a TSV data file whose lines each look like this:
 *
 *   LAST_NAME  FIRST_NAME  ID AGE
 *
 * Once compiled, you can run this program like so:
 *   ./debug_3 data.tsv
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

struct person {
  string last_name;
  string first_name;
  string id;
  int age;
};


/*
 * This function counts and returns the number of entries in a TSV file.  The
 * number of entries is counted as the number of non-empty lines.
 *
 * Hint: there shouldn't be any bugs in this function.
 */
int count_tsv_file_entries(ifstream& infile) {
  string line;
  int count = 0;

  // Make sure the file cursor is at the beginning and then count the lines.
  infile.seekg(0);
  do {
    getline(infile, line);
    if (line.length() > 0) {
      count++;
    }
  } while (!infile.eof());

  // Make sure the file's ready to read with the cursor at the beginning.
  infile.clear();
  infile.seekg(0);
  return count;
}


/*
 * This function reads people from a specified data file (with TSV format as
 * described in the file header) into an array of person structs and returns
 * the number of people read.
 */
int read_people(char* filename, person*& people) {
  ifstream infile(filename);
  int i = 0, n = count_tsv_file_entries(infile);
  person new_person;
  people = new person[n];

  do {
    infile >> new_person.last_name >> new_person.first_name >> new_person.id
      >> new_person.age;
    people[i++] = new_person;
  } while (i < n);

  return n;
}


/*
 * This function computes and returns the average age of all of the people in
 * an array of person structs.
 */
float compute_avg_age(person* people, int n) {
  float avg = 0;
  for (int i = 0; i < n; i++) {
    avg += people[i].age;
  }
  avg = (avg / n);
  return avg;
}


/*
 * This function computes and returns the maximum age of all of the people in
 * an array of person structs.
 */
int compute_max_age(person* people, int n) {
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (max < people[i].age) {
      max = people[i].age;
    }
  }
  return max;
}


int main(int argc, char** argv) {
  if (argc < 2) {
    cout << "Error: must specify a data file."
      << endl << endl;
    cout << "usage: " << argv[0] << " <data_file>" << endl;
    return 1;
  }

  person* people;
  int n = read_people(argv[1], people);
  float avg_age = compute_avg_age(people, n);
  int max_age = compute_max_age(people, n);

  cout << "The average age of the " << n << " people is: " << avg_age
    << endl;
  cout << "The maximum age of the " << n << " people is: " << max_age
    << endl;

  return 0;  
}