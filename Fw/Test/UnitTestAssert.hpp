/*
 * UnitTestAssert.hpp
 *
 *  Created on: Feb 8, 2016
 *      Author: tcanham
 *  Revised July 2020
 *      Author: bocchino
 */

#ifndef TEST_UNITTESTASSERT_HPP_
#define TEST_UNITTESTASSERT_HPP_

#include <Fw/Types/Assert.hpp>

namespace Test {

    class UnitTestAssert: public Fw::AssertHook {
        public:
            UnitTestAssert();
            virtual ~UnitTestAssert();
            // function for hook
            void doAssert(void);
            void reportAssert(
                    FILE_NAME_ARG file,
                    NATIVE_UINT_TYPE lineNo,
                    NATIVE_UINT_TYPE numArgs,
                    AssertArg arg1,
                    AssertArg arg2,
                    AssertArg arg3,
                    AssertArg arg4,
                    AssertArg arg5,
                    AssertArg arg6
                    );
            // retrieves assertion failure values
            void retrieveAssert(
                FILE_NAME_ARG file,
                NATIVE_UINT_TYPE& lineNo,
                NATIVE_UINT_TYPE& numArgs,
                AssertArg& arg1,
                AssertArg& arg2,
                AssertArg& arg3,
                AssertArg& arg4,
                AssertArg& arg5,
                AssertArg& arg6
                ) const;

            // check whether assertion failure occurred
            bool assertFailed() const;

            // clear assertion failure
            void clearAssertFailure();

        private:
#if FW_ASSERT_LEVEL == FW_FILEID_ASSERT
            FILE_NAME_ARG m_file;
#else
            char m_file[256];
#endif
            NATIVE_UINT_TYPE m_lineNo;
            NATIVE_INT_TYPE m_numArgs;
            AssertArg m_arg1;
            AssertArg m_arg2;
            AssertArg m_arg3;
            AssertArg m_arg4;
            AssertArg m_arg5;
            AssertArg m_arg6;

            // Whether an assertion failed
            bool m_assertFailed;

            // The previous assert hook
            AssertHook *m_previousAssertHook;

    };

} /* namespace Test */

#endif /* TEST_UNITTESTASSERT_HPP_ */
