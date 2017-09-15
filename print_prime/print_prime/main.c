//
//  main.c
//  print_prime
//
//  Created by Anoja Rajalakshmi on 9/14/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//
/*
 Create a list of consecutive integers from 2 to n: (2, 3, 4, …, n).
 Initially, let p equal 2, the first prime number.
 Starting from p, count up in increments of p and mark each of these numbers greater than p itself in the list. These numbers will be 2p, 3p, 4p, etc.; note that some of them may have already been marked.
 Find the first number greater than p in the list that is not marked. If there was no such number, stop. Otherwise, let p now equal this number (which is the next prime), and repeat from step 3.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void SieveOfEratosthenes(int n){
    bool prime[n+1];// Create a boolean array "prime[0..n]"
    memset(prime, true, sizeof(prime)); //initialize all entries it as true.
    
    for (int p=2; p*p<=n; p++){
        if (prime[p]){ // If prime[p] is not changed, then it is a prime
            for (int i=p*2; i<=n; i += p) // Update all multiples of p
                prime[i] = false;
        }
    }
    
    // Print all prime numbers
    for (int p=2; p<=n; p++)
        if (prime[p])
            printf("%d ",p);
}

int main(int argc, const char * argv[]) {
    int n = 10;
    printf("Following are the prime numbers smaller than or equal to %d\n",n );
    SieveOfEratosthenes(n);
    return 0;
}
