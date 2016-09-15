#include<conio.h>
#include<stdio.h>

//Declaration of constants so that we never change the cost of pokemons in our program
const int pikachu_cost=6;
const int squirtle_cost=5;
const int charmander_cost=5;

//Function to caluclate the minimal cost of the pokemons a customer shops
float funksum(int pikachu_quantity,int squirtle_quantity,int charmander_quantity)
{
float res;

if(pikachu_quantity>0||squirtle_quantity>0||charmander_quantity>0)
{
if(pikachu_quantity>=1&&squirtle_quantity>=1&&charmander_quantity>=1){
//Applying 20%discount on three different pokemons
res=funksum(pikachu_quantity-1,squirtle_quantity-1,charmander_quantity-1)+(pikachu_cost+squirtle_cost+charmander_cost)-(pikachu_cost+squirtle_cost+charmander_cost)*0.2;
return res;
}
else if(pikachu_quantity>=1&&squirtle_quantity>=1){
//Applying 10%discount on two different pokemons
res=funksum(pikachu_quantity-1,squirtle_quantity-1,charmander_quantity)+(pikachu_cost+squirtle_cost)-(pikachu_cost+squirtle_cost)*0.1;
return res;
}
else if(pikachu_quantity>=1&&charmander_quantity>=1){
//Applying 10%discount on two different pokemons
res=funksum(pikachu_quantity-1,squirtle_quantity,charmander_quantity-1)+(pikachu_cost+charmander_cost)-(pikachu_cost+charmander_cost)*0.1;
return res;
}
else if(squirtle_quantity>=1&&charmander_quantity>=1){
//Applying 10%discount on two different pokemons
res=funksum(pikachu_quantity,squirtle_quantity-1,charmander_quantity-1)+(squirtle_cost+charmander_cost)-(squirtle_cost+charmander_cost)*0.1;
return res;
}
else if(pikachu_quantity>=1){
//No discounts on single set of pokemons
res=funksum(pikachu_quantity-1,squirtle_quantity,charmander_quantity)+pikachu_cost;
return res;
}
else if(squirtle_quantity>=1){
//No discounts on single set of pokemons
res=funksum(pikachu_quantity,squirtle_quantity-1,charmander_quantity)+squirtle_cost;
return res;
}
else if(charmander_quantity>=1){
//No discounts on single set of pokemons
res=funksum(pikachu_quantity,squirtle_quantity,charmander_quantity-1)+charmander_cost;
return res;
}
else{
return 0;
}
}
else{
return res;
}

}




void main()
{

//initialising variables
float total=0.0;
int pikachu_quantity=0;
int squirtle_quantity=0;
int charmander_quantity=0;

//clearscreen function
clrscr();
//Scaning for the nuber of pokemons .Input given by the user.
printf("\n Enter the number of pikachus you got:");
scanf("%d",&pikachu_quantity);
printf("\n Enter the number of squirtle you got:");
scanf("%d",&squirtle_quantity);
printf("\n Enter the number of charmander you got:");
scanf("%d",&charmander_quantity);


//calling the recursive function.
total=funksum(pikachu_quantity,squirtle_quantity,charmander_quantity);

//printing the total cost after computing the optimal cost.
printf("\n price of the pokemons after applying best possible discount is:%f",total);
//get charecter function for a pause, so that we can see the output :);
getch();
}