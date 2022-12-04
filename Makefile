.PHONY = all clean
all: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
1:
	g++ 2022-1/main.cpp -o 2022-1/1.out
2:
	g++ 2022-2/main.cpp -o 2022-2/2.out
3:
	g++ 2022-3/main.cpp -o 2022-3/3.out
4:
	g++ 2022-4/main.cpp -o 2022-4/4.out
5:
	g++ 2022-5/main.cpp -o 2022-5/5.out
6:
	g++ 2022-6/main.cpp -o 2022-6/6.out
7:
	g++ 2022-7/main.cpp -o 2022-7/7.out
8:
	g++ 2022-8/main.cpp -o 2022-8/8.out
9:
	g++ 2022-9/main.cpp -o 2022-9/9.out
10:
	g++ 2022-10/main.cpp -o 2022-10/10.out
11:
	g++ 2022-11/main.cpp -o 2022-11/11.out
12:
	g++ 2022-12/main.cpp -o 2022-12/12.out
13:
	g++ 2022-13/main.cpp -o 2022-13/13.out
14:
	g++ 2022-14/main.cpp -o 2022-14/14.out
15:
	g++ 2022-15/main.cpp -o 2022-15/15.out
16:
	g++ 2022-16/main.cpp -o 2022-16/16.out
17:
	g++ 2022-17/main.cpp -o 2022-17/17.out
18:
	g++ 2022-18/main.cpp -o 2022-18/18.out
19:
	g++ 2022-19/main.cpp -o 2022-19/19.out
20:
	g++ 2022-20/main.cpp -o 2022-20/20.out
21:
	g++ 2022-21/main.cpp -o 2022-21/21.out
22:
	g++ 2022-22/main.cpp -o 2022-22/22.out
23:
	g++ 2022-23/main.cpp -o 2022-23/23.out
24:
	g++ 2022-24/main.cpp -o 2022-24/24.out
25:
	g++ 2022-25/main.cpp -o 2022-25/25.out
	@echo "Source Files compiled if existing, you need to get the input files yourself (input.txt for a given day)"

clean:
	@echo "Cleaning binaries"
	rm -rf */*.out
