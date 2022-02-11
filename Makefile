clean:
	rm -f */main

run:
	cd day1 && g++ main.cpp -o main && ./main
	cd day2 && g++ main.cpp -o main && ./main
	cd day3 && g++ main.cpp -o main && ./main
