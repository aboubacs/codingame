import argparse
from templite import Templite

parser = argparse.ArgumentParser(description='Pre-processor of Saphyra project.')

parser.add_argument(
    '--challenge',
    required=True,
    help='Set the challenge to use for processing'
)

mode_group = parser.add_mutually_exclusive_group(
    required=True
)
mode_group.add_argument(
    '--test', 
    action='store_true'
)
mode_group.add_argument(
    '--benchmark', action='store_true'
)
mode_group.add_argument(
    '--debug', 
    action='store_true'
)
mode_group.add_argument(
    '--production', 
    action='store_true'
)

args = parser.parse_args()

print(args)