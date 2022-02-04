#!/usr/bin/python3

with open("build/ZAPD/BuildInfo.cpp", "w+") as buildFile:
    label = " ~ Development version"
    buildFile.write("extern const char gBuildHash[] = \"" + label + "\";\n")
