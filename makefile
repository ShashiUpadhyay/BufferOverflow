all: compile_vuln_program compile-attack-string

compile_vuln_program: vuln_program.c
	gcc -m32 -g vuln_program.c -fno-stack-protector -z execstack -static -o vuln_program

compile-attack-string: attack-string.c
	gcc -m32 attack-string.c -o attack-string

perform_buffer_overflow:
	./vuln_program < ./attack.input
