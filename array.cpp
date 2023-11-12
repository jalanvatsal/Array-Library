//
//  main.cpp
//  Project 4
//
//  Created by Vatsal Jalan on 5/11/2566 BE.
//

#include <iostream>
#include<string>
using namespace std;

int reduplicate(string a[], int n);
int locate(const string a[], int n, string target);
int locationOfMax(const string a[], int n);
int circleLeft(string a[], int n, int pos);
int enumerateRuns(const string a[], int n);
int flip(string a[], int n);
int locateDifference(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int locateAny(const string a1[], int n1, const string a2[], int n2);
int divide(string a[], int n, string divider);

int main() {
    
    string folks[6] = { "donald", "tim", "", "chris", "nikki", "donald" };
    string group[5] = { "donald", "tim", "donald", "", "chris" };
    
    locateDifference(folks, 0, group, 5); 
    
}


int reduplicate(string a[], int n){
    
    // errror checking
    if(n < 0){
        return -1;
    }
    
    // appending each element to the end of itself
    for(int i = 0; i < n; i++){
        a[i] += a[i];
    }
    
    return n;
}

int locate(const string a[], int n, string target){
    
    // error checking
    if(n < 0){
        return -1;
    }
    
    // looping through array to find at which position target is found
    for(int i = 0; i < n; i++){
        if(a[i] == target){
            return i;
        }
    }
    
    return -1;
}

int locationOfMax(const string a[], int n){
    
    // error checking
    if(n < 0){
        return -1;
    }
    
    int counter = 0;
    
    // comparing each string to every other string in the array
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] >= a[j]){
                counter++;
            }
        }
        // check to see when we have found an element that is greater or equal to the amount of interesting elements in the array
        if(counter == n){
            return i;
        }
        counter = 0;
    }
    
    return -1;
}

int circleLeft(string a[], int n, int pos){
    
    //error checking
    
    if(n < 0 || pos < 0){
        return -1;
    }
    string temp = a[pos];
    
    int n_elements_after_pos = (n - 1) - pos;
    
    for(int i = pos; i <= pos + (n_elements_after_pos - 1); i++){
        a[i] = a[i+1];
    }
    
    a[n - 1] = temp;
    
    return pos;
}

int enumerateRuns(const string a[], int n){
    // error checking
    if(n < 0){
        return -1;
    }
    
    int k = 0;
    int counter = 0;
    int num_sequences = 0;
    
    while(k < n){
        
        for(int j = k; j < n; j++){
            if(a[k] == a[j]){
                counter++;
            } else {
                break;
            }
        }
        // increment k by counter to jump to next new element after analyzing consecutive elements
        k += counter;
        num_sequences++;
        counter = 0;
        
    }
    
    return num_sequences;
}

int flip(string a[], int n){
    
    if(n < 0){
        return -1;
    }

    // swapping elements of array
    for(int i = 0; i < n / 2; i++){
        string temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
    
    return n;

}

int locateDifference(const string a1[], int n1, const string a2[], int n2){
    
    if(n1 < 0 || n2 < 0){
        return -1;
    }
    
    bool n1_min = false;
    bool n2_min = false;
    
    // update value of bool variables to see which case we are in
    if(n1 < n2){
        n1_min = true;
    } else if(n2 < n1){
        n2_min = true;
    }
    
    if(n1_min){
        for(int i = 0; i < n1; i++){
            if(a1[i] != a2[i]){
                return i;
            }
        }
        return n1;
    } else if(n2_min){
        for(int i = 0; i < n2; i++){
            if(a1[i] != a2[i]){
                return i;
            }
        }
        return n2;
    }
    
    // At this point n1 is equal to n2
    for(int i = 0; i < n1; i++){
        if(a1[i] != a2[i]){
            return i;
        }
    }
    return n1;
    
}

int subsequence(const string a1[], int n1, const string a2[], int n2){

    if(n1 < 0 || n2 < 0){
        return -1;
    }
    
    // check if in a1 theres any string equal to first element of a2
    // if no then return -1
    // if yes then repeatedly run a counter and see if its equal to n2 if yes then return pos
    // else continue w/ loop
    
    for(int i = 0; i < n1; i++){
        if(a1[i] == a2[0]){
            int counter = 0;
            int k = i;
            for(int j = 0; j < n2 && k <= (i + (n2 - 1)); j++){
                if(a1[k] == a2[j]){
                    counter++;
                }
                k++;
            }
            if(counter == n2){
                return i;
            }
        }
    }
    
    return -1;

}

int locateAny(const string a1[], int n1, const string a2[], int n2){
    // error checking
    if(n1 < 0 || n2 < 0){
        return -1;
    }
    
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(a1[i] == a2[j]){
                return i;
            }
        }
    }
    
    return -1;
}

int divide(string a[], int n, string divider){
    
    // error checking
    if(n < 0){
        return -1;
    }
    
    for(int i = 0; i < n; i++){
        if(a[i] > divider){
            for(int j = i; j < n; j++){
                //move elements less than divider to front of array
                if(a[j] < a[i]){
                    string temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
    
    // find the earliest position of an element >= divider
    for(int i = 0; i < n; i++){
        if(a[i] >= divider){
            return i;
        }
    }
    
    return n;
}

