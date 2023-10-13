#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BPTRPlugin.h"

void BPTRPlugin::input(std::string file) {
   readParameterFile(file);
}

void BPTRPlugin::run() {}

void BPTRPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
 myCommand += "GENOME_LIST_STRING=\"\"; for NZ in `tail -n +2 "+PluginManager::addPrefix(myParameters["genes"])+"`; do GENOME_LIST_STRING=$GENOME_LIST_STRING\" "+myParameters["fasta"]+"/\"$NZ\".fna\"; done; bPTR -f$GENOME_LIST_STRING -s "+PluginManager::addPrefix(myParameters["samfile"])+" -o "+file+".tsv -plot "+file+".v -m \"coverage\" -ff";
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<BPTRPlugin> BPTRPluginProxy = PluginProxy<BPTRPlugin>("BPTR", PluginManager::getInstance());
