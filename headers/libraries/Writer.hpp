#pragma once

#include <vector>
#include <string>
#include <fstream>

#include "Libraries.hpp"

namespace algb
{
    namespace libr
    {
        class Writer
        {
        public:
            virtual ~Writer();

            virtual auto write(line_type const &line) -> bool_type const = 0;
            virtual auto write(lines_type const &lines) -> bool_type const = 0;
        };

        class FileWriter : public Writer
        {
        private:
            const path_type path;
            std::ofstream out;

        public:
            FileWriter(path_type const &path);
            ~FileWriter();

            auto write(line_type const &line) -> bool_type const override;
            auto write(lines_type const &lines) -> bool_type const override;
        };

        class TerminalWriter : public Writer
        {
        public:
            TerminalWriter();
            ~TerminalWriter();

            auto write(line_type const &line) -> bool_type const override;
            auto write(lines_type const &lines) -> bool_type const override;
        };
    }
}