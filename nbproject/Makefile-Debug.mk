#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Grid_Challenge.o \
	${OBJECTDIR}/KnightL_on_a_Chessboard.o \
	${OBJECTDIR}/Roads_and_Libraries.o \
	${OBJECTDIR}/Super_Reduced_String.o \
	${OBJECTDIR}/The_Story_of_a_Tree.o \
	${OBJECTDIR}/URI_CHEFE_1469.o \
	${OBJECTDIR}/URI_REDUZINDO_DETALHES_EM_UM_MAPA_2404.o \
	${OBJECTDIR}/URI_TODOS_OS_DISCOS_CONSIDERADOS.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hackerrank.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hackerrank.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hackerrank ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Grid_Challenge.o: Grid_Challenge.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Grid_Challenge.o Grid_Challenge.cpp

${OBJECTDIR}/KnightL_on_a_Chessboard.o: KnightL_on_a_Chessboard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/KnightL_on_a_Chessboard.o KnightL_on_a_Chessboard.cpp

${OBJECTDIR}/Roads_and_Libraries.o: Roads_and_Libraries.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Roads_and_Libraries.o Roads_and_Libraries.cpp

${OBJECTDIR}/Super_Reduced_String.o: Super_Reduced_String.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Super_Reduced_String.o Super_Reduced_String.cpp

${OBJECTDIR}/The_Story_of_a_Tree.o: The_Story_of_a_Tree.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/The_Story_of_a_Tree.o The_Story_of_a_Tree.cpp

${OBJECTDIR}/URI_CHEFE_1469.o: URI_CHEFE_1469.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/URI_CHEFE_1469.o URI_CHEFE_1469.cpp

${OBJECTDIR}/URI_REDUZINDO_DETALHES_EM_UM_MAPA_2404.o: URI_REDUZINDO_DETALHES_EM_UM_MAPA_2404.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/URI_REDUZINDO_DETALHES_EM_UM_MAPA_2404.o URI_REDUZINDO_DETALHES_EM_UM_MAPA_2404.cpp

${OBJECTDIR}/URI_TODOS_OS_DISCOS_CONSIDERADOS.o: URI_TODOS_OS_DISCOS_CONSIDERADOS.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/URI_TODOS_OS_DISCOS_CONSIDERADOS.o URI_TODOS_OS_DISCOS_CONSIDERADOS.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hackerrank.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
