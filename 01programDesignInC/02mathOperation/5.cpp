#include <stdio.h>
#include <inttypes.h>

int main() {
	int8_t a = 66; // (-128 - 127, 127(011...11) 的补码是 -128(10...01), 但 -128 的反码不是 127)
	// int 通过操作系统，编译器决定
	int b = 77;
	// printf("%d\n", sizeof(a));
	// warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long unsigned int’ [-Wformat=]
	// =>
	// printf("a = %lu, b = %lu\n", sizeof(a), sizeof(b));
	// printf("b = %d\n", b);
	// printf("b = %PRId8\n", a);
	/* compile error:
	unknown conversion type character ‘P’ in format [-Wformat=]
	printf("b = %PRId8\n", a);
	 */

	// PRIDx (macro)
	// printf("%s\n", PRId8);
	// printf("%s\n", PRId16);
	// printf("%s\n", PRId32);
	// printf("%s\n", PRId64);
	// "" and "" ""
	// printf("helloworld\n");
	// printf("hello" "world\n");

	/* error fix with macro */
	// printf("b = %" PRId8 "\n", a);

	printf("INT8_MIN = %d\n", INT8_MIN);
	printf("INT8_MAX = %d\n", INT8_MAX);
	printf("INT16_MIN = %d\n", INT16_MIN);
	printf("INT16_MAX = %d\n", INT16_MAX);
	printf("INT32_MIN = %d\n", INT32_MIN);
	printf("INT32_MAX = %d\n", INT32_MAX);
	printf("INT64_MIN = %ld\n", INT64_MIN);
	printf("INT64_MAX = %ld\n", INT64_MAX);
	return 0;
}