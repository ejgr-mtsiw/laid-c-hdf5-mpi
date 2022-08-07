/*
 ============================================================================
 Name        : disjoint_matrix_mpi.h
 Author      : Eduardo Ribeiro
 Description : Structures and functions to manage the disjoint matrix in MPIIO
 ============================================================================
 */

#ifndef MPI_DISJOINT_MATRIX_H
#define MPI_DISJOINT_MATRIX_H

#include "types/dataset_hdf5_t.h"
#include "types/dataset_t.h"
#include "types/dm_t.h"
#include "types/oknok_t.h"

#include <stdint.h>

uint32_t roundUp(uint32_t numToRound, uint32_t multiple);

/**
 * Creates the dataset containing the disjoint matrix with attributes as columns
 */
oknok_t mpi_create_line_dataset(const dataset_hdf5_t* hdf5_dset,
								const dataset_t* dset, const dm_t* dm);

/**
 * Creates the dataset containing the disjoint matrix with attributes as
 * lines
 */
oknok_t mpi_create_column_dataset(const dataset_hdf5_t* hdf5_dset,
								  const dataset_t* dset, const dm_t* dm,
								  const int rank, const int size);

/**
 * Writes the matrix atributes in the dataset
 */
herr_t mpi_write_disjoint_matrix_attributes(const hid_t dataset_id,
											const uint32_t n_attributes,
											const uint32_t n_matrix_lines);

/**
 * Writes the line totals metadata to the dataset
 */
oknok_t mpi_write_line_totals(const dataset_hdf5_t* hdf5_dset, const dm_t* dm,
							  const uint32_t* data);

/**
 * Writes the attribute totals metadata to the dataset
 */
oknok_t mpi_write_attribute_totals(const dataset_hdf5_t* hdf5_dset,
								   const uint32_t* data, const uint32_t start,
								   const uint32_t n_lines,
								   const uint32_t n_attributes);

#endif // MPI_DISJOINT_MATRIX_H