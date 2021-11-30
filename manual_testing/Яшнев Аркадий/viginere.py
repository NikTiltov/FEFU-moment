russian = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя"

plain_text, key = input(), input()

res, idx = "", 0
for i in range(0, len(plain_text)):
    if plain_text[i] == ' ':
        res += ' '
        continue
    text_pos = russian.find(plain_text[i])
    key_pos = russian.find(key[idx])
    res += russian[(text_pos + key_pos) % 33]
    idx = (idx + 1) % len(key)

print(res)
