#ifndef _SPECREADER_H_
#define _SPECREADER_H_

#include <string>
#include <vector>

namespace apngasm {
  namespace spec {

    // Delay parameter.
    typedef struct {
      unsigned int num;
      unsigned int den;
    } Delay;

    // Frame information.
    typedef struct {
      std::string filePath;
      Delay delay;
    } FrameInfo;

    namespace priv {
      class ISpecReaderImpl;
    }

    class SpecReader
    {
    public:
      // Initialize SpecReader object.
      SpecReader(const std::string& filePath);

      // Finalize SpecReader object.
      ~SpecReader();

      // Return animation name.
      const std::string& getName() const;

      // Return loops.
      unsigned int getLoops() const;

      // Return flag of skip first.
      bool getSkipFirst() const;

      // Return frame information vector.
      const std::vector<FrameInfo>& getFrameInfos() const;

    private:
      // Implements object pointer.
      const priv::ISpecReaderImpl* _pImpl;

    };  // class SpecReader

  } // namespacce spec
} // namespacce apngasm

#endif  // _SPECREADER_H_
