#!/bin/bash

# Check if the metroid.py file exists
if [ ! -f metroid.py ]; then
    echo "Error: metroid.py not found!"
    exit 1
fi

# Run metroid.py with Python 3
python3 metroid.py

# Check the exit status of the Python script
if [ $? -eq 0 ]; then
    echo "metroid.py executed successfully."
else
    echo "metroid.py failed to execute."
    exit 1
fi

