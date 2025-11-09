#!/bin/bash

# Create test directory
echo "Creating test files..."
mkdir -p test_files
cd test_files

# Test 1: Basic replacement
echo "Hello world, this is a test file.
Hello again, hello everyone." > test1.txt

# Test 2: Empty file
touch empty.txt

# Test 3: No matches
echo "This file has no matching patterns." > nomatch.txt

# Test 4: Multiple repetitions
echo "aaa aaa aaa aaa" > repeat.txt

# Test 5: Overlapping replacement
echo "aaaaa" > overlap.txt

# Test 6: Special characters
printf "Line1\nTab\tEnd" > special.txt

# Test 7: Multi-line replacement
echo "First line
Second line with target
Third line
Target appears again here" > multiline.txt

# Test 8: Case sensitivity
echo "Hello HELLO hello HeLlO" > case.txt

# Test 9: Replace with empty string
echo "Remove all the word target from this sentence." > remove.txt

echo "Test files created!"
echo ""

# Run tests
echo "=== Starting Tests ==="
echo ""

# Get current directory absolute path
CURRENT_DIR=$(pwd)
REPLACE_PROGRAM="../replace"

# Test 1: Basic replacement
echo "Test 1: Basic replacement (Hello -> Hi)"
$REPLACE_PROGRAM "test1.txt" "Hello" "Hi"
echo "Input file:"
cat "test1.txt"
echo "Output file:"
cat "test1.txt.replace"
echo ""

# Test 2: Empty file
echo "Test 2: Empty file"
$REPLACE_PROGRAM "empty.txt" "abc" "xyz"
if [ -s "empty.txt.replace" ]; then
    echo "FAIL: Empty file test failed - output file should be empty"
else
    echo "PASS: Empty file test passed"
fi
echo ""

# Test 3: No matches
echo "Test 3: No matches"
$REPLACE_PROGRAM "nomatch.txt" "abc" "xyz"
diff "nomatch.txt" "nomatch.txt.replace" > /dev/null
if [ $? -eq 0 ]; then
    echo "PASS: No match test passed"
else
    echo "FAIL: No match test failed"
fi
echo ""

# Test 4: Multiple repetitions
echo "Test 4: Multiple repetitions (aa -> b)"
$REPLACE_PROGRAM "repeat.txt" "aa" "b"
echo "Input: aaa aaa aaa aaa"
echo "Output: $(cat repeat.txt.replace)"
echo ""

# Test 5: Overlapping replacement
echo "Test 5: Overlapping replacement (aaa -> b)"
$REPLACE_PROGRAM "overlap.txt" "aaa" "b"
echo "Input: aaaaa"
echo "Output: $(cat overlap.txt.replace)"
echo ""

# Test 6: Special characters
echo "Test 6: Special characters"
$REPLACE_PROGRAM "special.txt" $'\n' "[NEWLINE]"
echo "Output file content:"
cat "special.txt.replace"
echo ""

# Test 7: Multi-line replacement
echo "Test 7: Multi-line replacement (target -> REPLACED)"
$REPLACE_PROGRAM "multiline.txt" "target" "REPLACED"
echo "Output file:"
cat "multiline.txt.replace"
echo ""

# Test 8: Case sensitivity
echo "Test 8: Case sensitivity (hello -> Hi)"
$REPLACE_PROGRAM "case.txt" "hello" "Hi"
echo "Output: $(cat case.txt.replace)"
echo ""

# Test 9: Replace with empty string
echo "Test 9: Replace with empty string (target -> '')"
$REPLACE_PROGRAM "remove.txt" "target " ""
echo "Output: $(cat remove.txt.replace)"
echo ""

# Error handling tests
echo "=== Error Handling Tests ==="
echo ""

# Test 10: Wrong number of arguments
echo "Test 10: Wrong number of arguments"
$REPLACE_PROGRAM "test1.txt" "hello"
echo ""

# Test 11: File doesn't exist
echo "Test 11: File doesn't exist"
$REPLACE_PROGRAM "nonexistent.txt" "a" "b"
echo ""

# Test 12: s1 is empty string
echo "Test 12: s1 is empty string"
$REPLACE_PROGRAM "test1.txt" "" "replacement"
echo ""

echo "=== Testing Completed ==="
echo "All test files generated in $CURRENT_DIR directory"
echo "Check .replace files to verify results"