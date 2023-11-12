# Array-Library

--- Description of functions to be included in library ---

int reduplicate(string a[], int n);
For each of the n elements of the array, append that element to that same element. Return n. Here's an example:
string stuff[6] = { "mahi", "bon", "cous", "", "tar", "mur" };
int j = reduplicate(stuff, 6);  // returns 6
    // now stuff[0] is "mahimahi", stuff[1] is "bonbon", stuff[2] is "couscous",
    // stuff[3] is "", stuff[4] is "tartar", and stuff[5] is "murmur"
    
int locate(const string a[], int n, string target);
Return the position of a string in the array that is equal to target; if there is more than one such string, return the smallest position number of such a matching string. Return −1 if there is no such string. As noted above, case matters: Do not consider "CHriS" to be equal to "cHrIS".

int locationOfMax(const string a[], int n);
Return the position of a string in the array such that that string is >= every string in the array. If there is more than one such string, return the smallest position number of such a string. Return −1 if the function should examine no elements of the array. Here's an example:
string cand[6] = { "donald", "asa", "ron", "vivek", "chris", "nikki" };
int k = locationOfMax(cand, 6);   // returns 3, since  vivek  is latest
                                  // in alphabetic order
                                  
int circleLeft(string a[], int n, int pos);
Eliminate the item at position pos by copying all elements after it one place to the left. Put the item that was thus eliminated into the last position of the array that the function knows about. Return the original position of the item that was moved to the end. Here's an example:
string running[5] = { "nikki", "donald", "asa", "tim", "ron" };
int m = circleLeft(running, 5, 1);  // returns 1
    // running now contains:  "nikki", "asa", "tim", "ron", "donald"

    
int enumerateRuns(const string a[], int n);
Return the number of sequences of one or more consecutive identical items in a.
string d[9] = {
    "chris", "doug", "tim", "tim", "vivek", "vivek", "vivek", "tim", "tim"
};
int p = enumerateRuns(d, 9);  //  returns 5
	   //  The five sequences of consecutive identical items are
	   //    "chris"
	   //    "doug"
	   //    "tim", "tim"
	   //    "vivek", "vivek", "vivek"
	   //    "tim", "tim"
    
int flip(string a[], int n);
Reverse the order of the elements of the array and return n. Here's an example:
string folks[6] = { "donald", "tim", "", "chris", "nikki", "donald" };
int q = flip(folks, 4);  // returns 4
    // folks now contains:  "chris"  ""  "tim"  "donald"  "nikki"  "donald"
    
int locateDifference(const string a1[], int n1, const string a2[], int n2);
Return the position of the first corresponding elements of a1 and a2 that are not equal. n1 is the number of interesting elements in a1, and n2 is the number of interesting elements in a2. If the arrays are equal up to the point where one or both runs out, return whichever value of n1 and n2 is less than or equal to the other. Here's an example:
string folks[6] = { "donald", "tim", "", "chris", "nikki", "donald" };
string group[5] = { "donald", "tim", "donald", "", "chris" };
int r = locateDifference(folks, 6, group, 5);  //  returns 2
int s = locateDifference(folks, 2, group, 1);  //  returns 1

int subsequence(const string a1[], int n1, const string a2[], int n2);
If all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where that subsequence begins. If the subsequence appears more than once in a1, return the smallest such beginning position in the array. Return −1 if a1 does not contain a2 as a contiguous subsequence. (Consider a sequence of 0 elements to be a subsequence of any sequence, even one with no elements, starting at position 0.) For example,
string names[10] = { "nikki", "ron", "tim", "vivek", "doug" };
string names1[10] = { "ron", "tim", "vivek" };
int t = subsequence(names, 5, names1, 3);  // returns 1
string names2[10] = { "nikki", "vivek" };
int u = subsequence(names, 4, names2, 2);  // returns -1

int locateAny(const string a1[], int n1, const string a2[], int n2);
Return the smallest position in a1 of an element that is equal to any of the n2 elements in a2. Return −1 if no element of a1 is equal to any element of a2. Here's an example:
string names[10] = { "nikki", "ron", "tim", "vivek", "doug" };
string set1[10] = { "donald", "doug", "vivek", "ron" };
int v = locateAny(names, 5, set1, 4);  // returns 1 (a1 has "ron" there)
string set2[10] = { "chris", "asa" };
int w = locateAny(names, 5, set2, 2);  // returns -1 (a1 has none)

int divide(string a[], int n, string divider);
Rearrange the elements of the array so that all the elements whose value is < divider come before all the other elements, and all the elements whose value is > divider come after all the other elements. Return the position of the first element that, after the rearrangement, is not < divider, or n if there are no such elements. Here's an example:
