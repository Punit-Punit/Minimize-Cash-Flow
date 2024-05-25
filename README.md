
This system minimizes the number of transactions between multiple persons who borrow money from each other.

Let's take an example. say we have the following Persons:
  1.Punit
  2.Saumy
  3.Aryan
  4.Vishal
  5.Anoop

  

 From                           To                        Amount

 Punit                         Aryan                       1000
 Punit                         Anoop                       2000
 Saumy                         Vishal                      3000
 Aryan                         Anoop                       4000
 Vishal                        Punit                       5000
 Anoop                         Saumy                       6000
 Aryan                         Saumy                       7000


Algorithm:

We initialize,
A Object with the name Person which contain {name,totalamount}
unordered_map -- map person with index.
2D vector - To store amount of transactions between Persons.


First, we calculate the total amount for every Person and store it in a vector.
totalamount = (amounts to be received) - (amounts to pay)

Now the idea is that we are finding the person which has minimum totalamount (Person A, totalamount  a(always negative))
and then finding the Person which has the maximum net amount (Person B, totalamount b). After that, we find minimum of absolute value of a and b {c = min(-a,b}.
Now A pays Rs. c to B and totalamount modifies, Now A needs to debit the (-a+c) amount and B needs to credit the (b-c) amount.

If any one OR both become zero, means it completely settles down.
We will continue the above process until all Person will not settle down completely.
