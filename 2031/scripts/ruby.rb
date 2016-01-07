1. find . -type f | wc -l
2. find . -type f | grep 'HW' | wc -l
3. find . -type f | grep -i 'hw' | wc -l
4. echo 'bookisbook' > test.txt | cat test.txt | grep -o 'book' | wc -l