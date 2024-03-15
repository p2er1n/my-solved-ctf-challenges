import base64

cipher = "MTgyMTg0NjUxMjVAMTYzLmNvbQ=="
print(base64.b64decode(cipher).decode("utf-8"))
