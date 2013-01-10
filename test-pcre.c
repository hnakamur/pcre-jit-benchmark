#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcre.h>

#define BUF_SIZE 0x10000

int main(int argc, char *argv[])
{
	pcre *r;
	pcre_extra *re;
        const char *error;
        int erroffset;
        int ovector[10];
	char *buf, *q;
	int l = 0;
        int studyoption;
	if (argc != 3) {
		fprintf(stderr, "Usage: cat in.file | %s <regexp> <jitflag>\n", argv[0]);
		return 0;
	}

	r = pcre_compile(argv[1], 0, &error, &erroffset, NULL);
        if (r == NULL) {
                fprintf(stderr, "PCRE compilation failed at offset %d: %s\n",
                        erroffset, error);
                return 1;
        }

        if (!strcmp(argv[2], "1")) {
#ifdef PCRE_STUDY_JIT_COMPILE
                studyoption = PCRE_STUDY_JIT_COMPILE;
#else
                fprintf(stderr, "JIT unsupported in PCRE\n");
                return 1;
#endif
        } else {
            studyoption = 0;
        }
        re = pcre_study(r, studyoption, &error);
        if (re == NULL) {
                fprintf(stderr, "PCRE study failed: %s\n", error);
                return 1;
        }

	buf = calloc(BUF_SIZE, 1);
	while (fgets(buf, BUF_SIZE - 1, stdin)) {
		++l;
		for (q = buf; *q; ++q); if (q > buf) *(q-1) = 0;
		if (pcre_exec(r, re, buf, q - buf, 0, PCRE_CONFIG_UTF8,
                    ovector, sizeof(ovector) / sizeof(int)) == 0)
			printf("%d:%s\n", l, buf);
	}
#ifdef PCRE_STUDY_JIT_COMPILE
        pcre_free_study(re);
#else
        pcre_free(re);
#endif
        pcre_free(r);
	free(buf);
	return 0;
}
