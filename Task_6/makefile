
all: signal_sender signal_receiver


signal_sender: signal_sender.c signal_sender.h
	gcc -Wall signal_sender.c -o signal_sender


signal_receiver: signal_receiver.c signal_receiver.h
	gcc -Wall signal_receiver.c -o signal_receiver


clean:
	rm -f signal_sender signal_receiver