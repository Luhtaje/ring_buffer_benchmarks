import re
import sys

if len(sys.argv) != 3:
    print("Usage: python split_data.py <input_filename> <date>")
    sys.exit(1)

input_filename = sys.argv[1]
date = sys.argv[2]

# Read the entire content from the input file
with open(input_filename, 'r') as f:
    content = f.read()


access_pattern = re.compile(r'BM_access_\S+')
construction_pattern = re.compile(r'BM_construction_\S+')
find_pattern = re.compile(r'BM_find_\S+')
insert_pattern = re.compile(r'BM_insert_\S+')
reserve_pattern = re.compile(r'BM_reserve_\S+')

access_data = re.findall(access_pattern, content)
construction_data = re.findall(construction_pattern, content)
find_data = re.findall(find_pattern, content)
insert_data = re.findall(insert_pattern, content)
reserve_data = re.findall(reserve_pattern, content)


# Write data to separate files 
with open(f'access/access_data{date}.txt', 'w') as access_file:
    access_file.write('\n'.join(access_data))

with open(f'construction/construction_data{date}.txt', 'w') as construction_file:
    construction_file.write('\n'.join(construction_data))

with open(f'find/find_data{date}.txt', 'w') as find_file:
    find_file.write('\n'.join(find_data))

with open(f'insert/insert_data{date}.txt', 'w') as insert_file:
    insert_file.write('\n'.join(insert_data))

with open(f'reserve/reserve_data{date}.txt', 'w') as reserve_file:
    reserve_file.write('\n'.join(reserve_data))