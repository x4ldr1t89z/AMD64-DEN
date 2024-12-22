import socket

target_host = "127.0.0.1"  # use localhost for same machine.
target_port = 9998         # Port number of the server

# Create a socket object (TCP)
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Connect to the server
client.connect((target_host, target_port))
# Send some data to the server
client.send(b"Hello, Server!")
# Receive a response from the server
response = client.recv(4096)
print(f"[*] Server response: {response.decode()}")
client.close()
