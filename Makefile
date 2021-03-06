include warnings.mk
CC=g++
CFLAGS=-g3 -O2 $(filter-out -Wmissing-format-attribute,$(filter-out -Wundef,$(WARNING_FLAGS))) -I./
LIBS=

LIB_SRCS=\
	bsmodel.C \
	bsmodels/bsmodel_10_vr.C \
	bsmodels/bsmodel_10_vr_support.C \
	bsmodels/bsmodel_1_v.C \
	bsmodels/bsmodel_2_vr.C \
	bsmodels/bsmodel_4_vr.C \
	bsmodels/bsmodel_4_vr_support.C \
	bsmodels/bsmodel_6_vr.C \
	bsmodels/bsmodel_6_vr_support.C \
	bsmodels/bsmodel_base.C \
	bsmodels/bsmodel_base_support.C \
	cboe_reader.C \
	histogram.C \
	jackwerth.C \
	levenberg_marquardt.C \
	levenberg_marquardt-binesh.C \
	matrix.C \
	svdecomposition.C \
	time2str.C \

BIN_SRCS=\
	main.C \
	test_jackwerth.C \
	test_trevor.C \

LEX_SRCS=\

LEX_C_SRCS=$(LEX_SRCS:l=C)

LIB_OBJS=$(LIB_SRCS:C=o)
BIN_OBJS=$(BIN_SRCS:C=o)
LEX_C_OBJS=$(LEX_C_SRCS:C=o)
SRCS=$(LIB_SRCS) $(BIN_SRCS) $(LEX_C_SRCS)
OBJS=$(LIB_OBJS) $(BIN_OBJS) $(LEX_C_OBJS)
CANDIDATES=$(filter %.d,$(patsubst %.C,%.d,$(patsubst %.c,%.d,$(SRCS))))
DEPS=$(join $(dir $(CANDIDATES)),$(addprefix .,$(notdir $(CANDIDATES))))

BINS=\
	main \
	test_jackwerth \
	test_trevor \

all: $(OBJS) $(BINS)

test: all
	./main data/2010/07/18/QQQQ-025300 data/2010/07/18/QQQQ-054408

git:
	/usr/local/bin/git commit -a --message "Automatic from Makefile"
	/usr/local/bin/git push

clean:
	/bin/rm -f core $(OBJS) $(BINS) $(LEX_C_SRCS) $(DEPS)

main: main.o $(LIB_OBJS)
	$(CC) $(CFLAGS) $(^) -o $(@) $(LIBS)

test_jackwerth: test_jackwerth.o $(LIB_OBJS)
	$(CC) $(CFLAGS) $(^) -o $(@) $(LIBS)

test_trevor: test_trevor.o $(LIB_OBJS)
	$(CC) $(CFLAGS) $(^) -o $(@) $(LIBS)

%.o: %.C
	$(CC) $(CFLAGS) -c $(filter %.C,$(^)) -o $(@)

.%.d: %.C
	@$(CC) $(CFLAGS) $(INCLUDES) -MT $(patsubst %.C,%.o,$(patsubst %.c,%.o,$(<))) -M $(<) -o $(@)

.%.d: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -MT $(patsubst %.C,%.o,$(patsubst %.c,%.o,$(<))) -M $(<) -o $(@)

-include $(DEPS)
