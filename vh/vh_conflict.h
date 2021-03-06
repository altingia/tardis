/*
 * vh_conflict.h
 *
 *  Created on: Apr 4, 2017
 *      Author: tardis
 */

#ifndef VH_VH_CONFLICT_H_
#define VH_VH_CONFLICT_H_

#include "../variants.h"

#define maxNumSV 100000 /* maximum number of SV's allowed to be reported. */

/* SVs which are selected for output are kept for conflict resolution */
typedef struct SV_selected{

	char *chromosome_name;
	int clusterId; // ID of the cluster selected
	char SVtype;// D: deletion, V: Inversion, I: insertion, E: tandam duplication, M: mobile element
	int posStart_SV, posEnd_SV;// The inside coordinates
	int posStart_SV_Outer, posEnd_SV_Outer;//The outside coordinates
	int sup[MAX_SAMPLES]; // support for the SV picked for each individual
	struct SV_selected* conflict_Next; // keep a link list of all other SVs selected which are in conlift with this SV (in hapolid genome)
} SV_selected;

//SV_selected listSelectedSV[maxNumSV];// the array of all the SVs selected till now
SV_selected **listSelectedSV;// the array of all the SVs selected till now


int conflictsAny(int i, int *supInd);
void addToListOfConflicts(int i, int j, int *countReads);
void addToConflict(int maxWeightSet, int *countReads);
void initConflict( int max_sv_count);
void vh_new_conflict_list(int);
void vh_enlarge_conflict_list(int, int);
SV_selected *vh_new_conflict_item(void);
void vh_free_conflict_list(int);
extern int current_conflict_size;
extern int numSV;

#endif /* VH_VH_CONFLICT_H_ */
