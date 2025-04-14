all: stack_overflow_debug_info stack_overflow_no_db_info \
     divide_by_zero_debug_info divide_by_zero_no_db_info \
     invalid_memory_debug_info invalid_memory_no_db_info

# === Debug Builds ===
stack_overflow_debug_info:
	g++ -g stack_overflow.cpp -o stack_overflow_debug_info

divide_by_zero_debug_info:
	g++ -g divide_by_zero.cpp -o divide_by_zero_debug_info

invalid_memory_debug_info:
	g++ -g invalid_memory.cpp -o invalid_memory_debug_info

# === No debug info Builds (no -g) ===
stack_overflow_no_db_info:
	g++ stack_overflow.cpp -o stack_overflow_no_db_info

divide_by_zero_no_db_info:
	g++ divide_by_zero.cpp -o divide_by_zero_no_db_info

invalid_memory_no_db_info:
	g++ invalid_memory.cpp -o invalid_memory_no_db_info


clean:
	rm -f stack_overflow_debug_info stack_overflow_no_db_info \
	      divide_by_zero_debug_info divide_by_zero_no_db_info \
	      invalid_memory_debug_info invalid_memory_no_db_info \
	      core* /tmp/core.*
