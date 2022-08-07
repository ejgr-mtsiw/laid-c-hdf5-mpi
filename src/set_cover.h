/*
 ============================================================================
 Name        : set_cover.h
 Author      : Eduardo Ribeiro
 Description : Structures and functions to apply the set cover algorithm
 ============================================================================
 */

#ifndef SET_COVER_H
#define SET_COVER_H

#include "types/cover_t.h"
#include "types/dataset_hdf5_t.h"
#include "types/oknok_t.h"

#include <stdint.h>

/**
 * Applies the set cover algorithm to the hdf5 dataset and prints
 * the minimum attribute set that covers all the lines
 */
oknok_t calculate_solution(const char* filename, cover_t* cover);

/**
 * Searches the attribute totals array for the highest score and returns the
 * correspondent attribute index.
 * Returns -1 if there are no more attributes available.
 */
int64_t get_best_attribute_index(cover_t* cover);

/**
 * Sets this attribute as selected
 */
oknok_t mark_attribute_as_selected(cover_t* cover, int64_t attribute);

/**
 * Updates the contribution of this line to the attributes totals
 */
oknok_t remove_line_contribution(cover_t* cover, const word_t* line);

/**
 * Updates the list of covered lines, adding the lines covered by column
 */
oknok_t update_covered_lines(cover_t* cover, word_t* column);

/**
 * Loads initial attribute totals from metadata dataset
 */
oknok_t load_initial_attribute_totals(uint32_t* attribute_totals,
									  const char* filename);

/**
 * Calculates the initial totals for all attributes
 */
void calculate_initial_sum(const char* filename, const cover_t* cover);

/**
 * Updates the attributes totals, removing the contribution of the lines
 * covered by column
 */
oknok_t update_attribute_totals(cover_t* cover, dataset_hdf5_t* line_dataset,
								word_t* column);

/**
 * Prints the attributes that are part of the solution
 */
void print_solution(FILE* stream, cover_t* cover);

/**
 * Initializes (zeroes) the cover parameters
 */
void init_cover(cover_t* cover);

/**
 * Frees the allocated resources
 */
void free_cover(cover_t* cover);

#endif