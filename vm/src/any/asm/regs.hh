/* Sun-$Revision: 30.10 $ */

/* Copyright 1992-2006 Sun Microsystems, Inc. and Stanford University.
   See the LICENSE file for license information. */


# ifdef INTERFACE_PRAGMAS
  # pragma interface
# endif


# include "_regs_pd.hh.incl"


extern "C" {                            // extern "C" for easier debugging
  void printLocation(Location l);
  char* locationName(Location l);       // what printLocation prints
}




// machine-specific implementations:

extern char* RegisterNames[];

// WARNING: duplicated in asmDefs_ppc.h
const fint NumNonVolRegisters       = HighestNonVolReg - LowestNonVolReg      + 1;
const fint NumLocalNonVolRegisters  = HighestNonVolReg - LowestLocalNonVolReg + 1;
const fint NumGlobalNonVolRegisters = LowestLocalNonVolReg - LowestNonVolReg;

inline bool isGloballyAllocatedRegister(Location r) {
  return isSet(GloballyAllocatedMask, r);
}

# ifdef SIC_COMPILER
inline bool isTrashedReg(Location r) { // true if r is trashed by calls
  return isRegister(r) && isSet(AllTrashedMask, r);
}
# endif

Location LocationOfSavedOutgoingArgInSendee(fint argNo /* -1 for rcvr*/);
