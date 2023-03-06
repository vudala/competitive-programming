

arr = ["ggg", "gat", "aaa", "atc", "atc", "agt", "aaa", "aaa"]

maior = 1
maior_code = ""
counts = {}
for i in arr:
    try:
        counts[i] += 1
    except KeyError:
        counts[i] = 1

    if counts[i] > maior:
        maior = counts[i]
        maior_code = i

print(maior)
print(maior_code)