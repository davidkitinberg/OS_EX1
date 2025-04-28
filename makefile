.PHONY: all Task_1 Task_2 Task_3 Task_4 Task_5 Task_6 Task_7 clean

all: Task_1 Task_2 Task_3 Task_4 Task_5 Task_6 Task_7

Task_1:
	$(MAKE) -C Task_1

Task_2:
	$(MAKE) -C Task_2

Task_3:
	$(MAKE) -C Task_3

Task_4:
	$(MAKE) -C Task_4

Task_5:
	$(MAKE) -C Task_5

Task_6:
	$(MAKE) -C Task_6

Task_7:
	$(MAKE) -C Task_7

clean:
	$(MAKE) -C Task_1 clean
	$(MAKE) -C Task_2 clean
	$(MAKE) -C Task_3 clean
	$(MAKE) -C Task_4 clean
	$(MAKE) -C Task_5 clean
	$(MAKE) -C Task_6 clean
	$(MAKE) -C Task_7 clean
