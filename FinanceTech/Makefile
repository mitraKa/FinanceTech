CC = g++
CCFLAGS = -Wall -lcppunit -ldl -std=c++11

OBJS = Interface.o main.o UserList.o AccountFactory.o Account.o Administrator.o Chequing.o CreditCard.o Credit.o Customer.o Debit.o LineOfCredit.o LogItem.o Profile.o RecTrans.o Savings.o User.o UserList.o

OBJS1 = Interface.o testMain.o UserList.o AccountFactory.o Account.o Administrator.o Chequing.o CreditCard.o Credit.o Customer.o Debit.o LineOfCredit.o LogItem.o Profile.o RecTrans.o Savings.o User.o UserList.o

OBJS2 = Interface.o UserList.o AccountFactory.o Account.o Administrator.o Chequing.o CreditCard.o Credit.o Customer.o Debit.o LineOfCredit.o LogItem.o Profile.o RecTrans.o Savings.o User.o UserList.o CreditCardTest.o Tester.o

all : main testMain cpptest

main : $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

testMain : $(OBJS1)
	$(CC) $(CCFLAGS) $^ -o $@

cpptest : $(OBJS2)
	$(CC) $(CCFLAGS) $^ -o $@

%.o : %.cc
	$(CC) $(CCFLAGS) -c $<

## generate the prerequistes and append to the desired file
.prereq : $(OBJS:.o=.cc) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cc) >> ./.prereq

## include the generated prerequisite file
include .prereq

.PHONY : clean
clean :
	rm -f *.o *~ # .#*

.PHONY : clean-all
clean-all : clean
	rm -f  main testMain cpptest
