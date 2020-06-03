/* 
 * File:   init.h
 * Author: C62081
 *
 * Created on May 5, 2020, 9:39 AM
 */

#ifndef INIT_H
#define	INIT_H

#ifdef	__cplusplus
extern "C" {
#endif

    void initDAC(void);
    void initCMP(void);
    void initOPA(void);
    void initTMR2(void);

#ifdef	__cplusplus
}
#endif

#endif	/* INIT_H */

