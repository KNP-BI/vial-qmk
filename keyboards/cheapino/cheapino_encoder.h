//
// Created by Thomas Haukland on 25/03/2023.
//
// matrix_row_t lives in matrix.h; we include it explicitly because encoder.h
// is included from sources other than keyboard code (drivers/encoder, for
// example) which may not transitively pull in matrix.h.
//
#pragma once

#include "matrix.h"

void fix_encoder_action(matrix_row_t current_matrix[]);
