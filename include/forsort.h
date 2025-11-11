//				FORSORT
//
// Author: Stew Forster (stew675@gmail.com)	Copyright (C) 2021-2025
//

#ifndef FORSORT_H
#define FORSORT_H
void forsort_basic(void *a, const size_t n, const size_t es,
	int (*is_lt)(const void *, const void *));
	
		
void forsort_stable(void *a, const size_t n, const size_t es,
	int (*is_lt)(const void *, const void *));
			
		
void forsort_inplace(void *a, const size_t n, const size_t es,
	int (*is_lt)(const void *, const void *),
	void *workspace, size_t worksize);
#endif
