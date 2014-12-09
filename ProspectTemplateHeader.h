#ifndef PROSPECTTEMPLATEHEADER_H_
#define PROSPECTTEMPLATEHEADER_H_

#include "Queue_Template.h"
#include "Prospects.h"
#include <ios>
#include <limits>
using namespace std;

void InfoRequest(Queue<Prospects>prospectList);

void BuildList(Queue<Prospects>prospectList);

void SaveProspectList(Queue<Prospects>prospectList);

#endif /* PROSPECTTEMPLATEHEADER_H_ */
