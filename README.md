# This system minimizes the number of transactions between multiple persons who borrow money from each other.



  Let's take an example. say we have the following Persons:
    1.Punit
    2.Saumy
    3.Aryan
    4.Vishal
    5.Anoop


&emsp;    **From**&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;                **To** &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; **Amount**
1. Punit  &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;             Aryan &emsp;&emsp;&emsp;&emsp;&emsp;          Rs 1000
2. Punit  &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;             Anoop &emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;         Rs 2000
3. Saumy  &emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;           Vishal  &emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;      Rs 3000
4. Aryan   &emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;           Anoop &emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp; Rs 4000
5. Vishal  &emsp;&emsp;&nbsp;&nbsp;&emsp;&emsp;&emsp;       Punit &emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp; Rs 5000
6. Anoop &emsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&emsp;&nbsp;&nbsp;       Saumy &emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Rs 6000
7. Aryan        &emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;       Saumy &emsp;&emsp;&emsp;&emsp;&emsp; Rs 7000


# Algorithm:

  We initialise,
  A Object with name Person which contain {name,totalamount} <br>
  unordered_map -- map person with index. <br>
  2D vector - To store amount of transactions between Persons.

  First,we calculate the total amount for every Person and store them in vector:

  totalamount = (amounts to be received) - (amounts to pay)

  Now the idea is that we are finding the person which has minimum totalamount (Person A, totalamount  a(always negative)) and then finding the Person which has the
  maximum net amount (Person B, totalamount b). After tha we find minimum of absolute value of a and b {c = min(-a,b}.
  Now A pays Rs. c to B and totalamount modifies,Now A need to debit (-a+c) amount and B needs to credit (b-c) amount.

If any one OR both become zero, means it completely settles down.
We will continue the above process until all Person will not settle down completely.
