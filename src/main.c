#include <argp.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

const char* argp_program_version = "E 0.0";
const char* argp_program_bug_address = "https://github.com/penguin-operator/e/issues";

char doc[] = "E language JIT compiler";
char args_doc[] = "[SRC..]";

struct argp_option opts[] = {
	{"execute", 'x', "CODE", 0, "execute the given code"},
	{"output", 'o', "FILE", 0, "output file"},
	{0},
};

struct args {
	char **input;
	int files;
	char *code;
	char *output;
} args;

error_t parse(int key, char* arg, struct argp_state *state) {
	struct args *args = state->input;
	switch (key) {
	case 'o':
		args->output = arg;
		break;
	case 'x':
		args->code = arg;
		break;
	case ARGP_KEY_ARG:
		if (args->input) args->input = realloc(args->input, (2+args->files)*sizeof(char*));
		else args->input = malloc(2*sizeof(char*));
		args->input[args->files++] = arg; 
		break;
	default:
		return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

struct argp argp = {opts, parse, args_doc, doc};

int main(int argc, char **argv, char **envp) {
	struct args args = {0};
	argp_parse(&argp, argc, argv, 0, 0, &args);
	return 0;
}
