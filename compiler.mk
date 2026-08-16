##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=compiler
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/User/Documents/codelite/compiler
ProjectPath            :=C:/Users/User/Documents/codelite/compiler/compiler
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/compiler
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=User
Date                   :=15/08/2026
CodeLitePath           :="C:/Program Files/CodeLite/share/codelite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/mingw64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/mingw64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/Users/User/Documents/codelite/compiler/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/mingw64/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/mingw64/mingw64/bin/ar.exe -r
CXX      := C:/mingw64/mingw64/bin/g++.exe
CC       := C:/mingw64/mingw64/bin/gcc.exe
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite/share/codelite
Objects0=$(IntermediateDirectory)/src_lexer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_tokens.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_parser.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_lexer.cpp$(ObjectSuffix): src/lexer.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/codelite/compiler/compiler/src/lexer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lexer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lexer.cpp$(PreprocessSuffix): src/lexer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lexer.cpp$(PreprocessSuffix) src/lexer.cpp

$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/codelite/compiler/compiler/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) src/main.cpp

$(IntermediateDirectory)/src_tokens.cpp$(ObjectSuffix): src/tokens.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/codelite/compiler/compiler/src/tokens.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_tokens.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_tokens.cpp$(PreprocessSuffix): src/tokens.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_tokens.cpp$(PreprocessSuffix) src/tokens.cpp

$(IntermediateDirectory)/src_parser.cpp$(ObjectSuffix): src/parser.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/codelite/compiler/compiler/src/parser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_parser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_parser.cpp$(PreprocessSuffix): src/parser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_parser.cpp$(PreprocessSuffix) src/parser.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


